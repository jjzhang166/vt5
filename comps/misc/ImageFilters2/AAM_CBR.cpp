#include "stdafx.h"
#include "AAM_CBR.h"
#include "misc_utils.h"
#include <math.h>

#include "nameconsts.h"
#include "clone.h"
#include "clonedata.h"
#include "ImagePane.h"
#include "PointList.h"

#define MaxColor color(-1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
//
//              Close by Reconstruction (AAM)
//
//
/////////////////////////////////////////////////////////////////////////////
#define szMaskType "mask_type"
#define szMaskSize "mask_size"

_ainfo_base::arg        CAamCbrInfo::s_pargs[] = 
{       
	{"Seed",       szArgumentTypeImage, 0, true, true },
	{"Img",       szArgumentTypeImage, 0, true, true },
	{"Result",    szArgumentTypeImage, 0, false, true },	
	{0, 0, 0, false, false },
};


/////////////////////////////////////////////////////////////////////////////

static __forceinline void TestPointCbr(
								int x, int y, int cur, color c,
								color **SrcRows, color **DstRows, byte **MaskRows,
								CPointList &points)
{
	color *pDst=DstRows[y]+x;
	color c2=SrcRows[y][x];
	color cc=__max(c,c2);
	if (*pDst>cc)
	{
		points.DelPoint(*pDst,cur); //������� ����� cur �� �������� ������ 
		*pDst=cc;
		points.AddPoint(cc,cur); //�������� ����� cur � ����� ������
	}
}

bool CAamCbrFilter::ReconstructionForClose(IImage2 *pSource, IImage2 *pResult)
{
	SIZE size;
	pSource->GetSize((int*)&size.cx,(int*)&size.cy);
	POINT ptOffset;
	pSource->GetOffset(&ptOffset);
	int w=size.cx;
	
	// [vanek] 12.12.2003: works with color convertors panes
	CImagePaneCache paneCache( pSource );

	//int nPaneCount = ::GetImagePaneCount( pSource );
	int nPaneCount = paneCache.GetPanesCount( );

	StartNotification(size.cy*5,nPaneCount);
	
	_ptr_t2<color*> smartSrcRows(size.cy);
	color** SrcRows=smartSrcRows.ptr;
	_ptr_t2<byte*> smartMaskRows(size.cy);
	byte** MaskRows=smartMaskRows.ptr;
	_ptr_t2<color*> smartDstRows(size.cy);
	color** DstRows=smartDstRows.ptr;

	for( int nPane=0;nPane<nPaneCount;nPane++ )
	{
		if( paneCache.IsPaneEnable(nPane) && IsPaneEnable(nPane) )    // mask not supported yet
		{
			CPointList points;
			points.CreateNew(size.cx,size.cy);
			for (int y=0; y<size.cy; y++)
			{
				color *pDst;
				pResult->GetRow(y,nPane,&pDst);
				DstRows[y]=pDst;
				color *pSrc;
				pSource->GetRow(y,nPane,&pSrc);
				SrcRows[y]=pSrc;
				for (int x=0; x<size.cx; x++,pDst++)
				{
					int cur=y*w+x;
					int c=*pDst;
					points.AddPoint(c,cur);
				}
				Notify(y);
			}
			int point_count=0;
			for (int c=0; c<=MaxColor; c++)
			{
				int cur=points.first[c];
				while(cur>=0)
				{
					int x=cur%w, y=cur/w;
					if(x<size.cx-1) //����� ������;
						TestPointCbr(x+1, y, cur+1, c, SrcRows, DstRows, MaskRows, points);
					if(x>0)          //����� �����;
						TestPointCbr(x-1, y, cur-1, c, SrcRows, DstRows, MaskRows, points);
					if(y<size.cy-1)  //����� �����;
						TestPointCbr(x, y+1, cur+size.cx, c, SrcRows, DstRows, MaskRows, points);
					if(y>0)          //����� ������;
						TestPointCbr(x, y-1, cur-size.cx, c, SrcRows, DstRows, MaskRows, points);
					cur=points.next[cur];
					if(point_count&0xFFFF0000)
						Notify(size.cy+point_count/size.cx*4);
					point_count++;
				}
			}
		}
		NextNotificationStage();
	}
	FinishNotification();
	return(true);
}

bool CAamCbrFilter::CloseByReconstructionAAM3(int nMaskType, int nMaskSize, IImage2 *pSource, IImage2 *pResult)
{
	if( !pSource || !pResult )
		return false;
	
	SIZE size;
	pSource->GetSize((int*)&size.cx,(int*)&size.cy);
	POINT ptOffset;
	pSource->GetOffset(&ptOffset);
	int w=size.cx;
	
	int nPaneCount;
	BSTR bstrName;
	IColorConvertor2* pIClrConv;
	pSource->GetColorConvertor((IUnknown**)&pIClrConv);

    // [vanek] 12.12.2003: works with color convertors panes
	CImagePaneCache paneCache( pSource );

	//nPaneCount = ::GetImagePaneCount( pSource );
	nPaneCount = paneCache.GetPanesCount( );
	
	pIClrConv->GetCnvName(&bstrName);
	pResult->CreateImage(size.cx, size.cy,bstrName, ::GetImagePaneCount( pSource ) ); 
	pResult->SetOffset( ptOffset ,TRUE);
	pResult->InitRowMasks();
	pIClrConv->Release();
	SysFreeString(bstrName);
	
	Dilate(nMaskType,nMaskSize,pSource,pResult);
	
	StartNotification(size.cy*5,nPaneCount);
	
	_ptr_t2<color*> smartSrcRows(size.cy);
	color** SrcRows=smartSrcRows.ptr;
	_ptr_t2<byte*> smartMaskRows(size.cy);
	byte** MaskRows=smartMaskRows.ptr;
	_ptr_t2<color*> smartDstRows(size.cy);
	color** DstRows=smartDstRows.ptr;
	
	for( int nPane=0;nPane<nPaneCount;nPane++ )
	{
		if( paneCache.IsPaneEnable(nPane) && IsPaneEnable(nPane))    // mask not supported yet
		{
			CPointList points;
			points.CreateNew(size.cx,size.cy);
			for (int y=0; y<size.cy; y++)
			{
				color *pDst;
				pResult->GetRow(y,nPane,&pDst);
				DstRows[y]=pDst;
				color *pSrc;
				pSource->GetRow(y,nPane,&pSrc);
				SrcRows[y]=pSrc;
				for (int x=0; x<size.cx; x++,pDst++)
				{
					int cur=y*w+x;
					int c=*pDst;
					points.AddPoint(c,cur);
				}
				Notify(y);
			}
			int point_count=0;
			for (int c=0; c<=MaxColor; c++)
			{
				int cur=points.first[c];
				while(cur>=0)
				{
					int x=cur%w, y=cur/w;
					if(x<size.cx-1) //����� ������;
						TestPointCbr(x+1, y, cur+1, c, SrcRows, DstRows, MaskRows, points);
					if(x>0)          //����� �����;
						TestPointCbr(x-1, y, cur-1, c, SrcRows, DstRows, MaskRows, points);
					if(y<size.cy-1)  //����� �����;
						TestPointCbr(x, y+1, cur+size.cx, c, SrcRows, DstRows, MaskRows, points);
					if(y>0)          //����� ������;
						TestPointCbr(x, y-1, cur-size.cx, c, SrcRows, DstRows, MaskRows, points);
					cur=points.next[cur];
					if((point_count++)&0xFFFF0000)
						Notify(size.cy+point_count/size.cx*4);
				}
			}
		}
		NextNotificationStage();
	}
	FinishNotification();
	return(true);
}


bool CAamCbrFilter::InvokeFilter()
{
	IImage3Ptr	ptrSeedImage( GetDataArgument("Seed") );
	IImage3Ptr	ptrSrcImage( GetDataArgument("Img") );
	IImage3Ptr	ptrDestImage( GetDataResult() );
	
	if( ptrSeedImage == NULL || ptrSrcImage == NULL || ptrDestImage == NULL )
		return false;

	// Are src and seed compatible?
	{
		SIZE size,size2;
		ptrSeedImage->GetSize((int*)&size.cx,(int*)&size.cy);
		ptrSrcImage->GetSize((int*)&size2.cx,(int*)&size2.cy);
		if (size.cx != size2.cx || size.cy != size2.cy) return(false);

		IColorConvertor2 *pIClrConv, *pIClrConv2;
		ptrSeedImage->GetColorConvertor((IUnknown**)&pIClrConv);
		ptrSrcImage->GetColorConvertor((IUnknown**)&pIClrConv2);
		pIClrConv->Release();
		pIClrConv2->Release();
		if(pIClrConv!=pIClrConv2) return(false);
	}

	ICompatibleObjectPtr ptrCO( ptrDestImage );
	if( ptrCO == NULL ) return false;
	if( S_OK != ptrCO->CreateCompatibleObject( ptrSrcImage, NULL, 0 ) )
	{			
		return false;
	}

	// copy seed to result image
	int nPaneCount;
	SIZE size;
	ptrSeedImage->GetSize((int*)&size.cx,(int*)&size.cy);
	nPaneCount = ::GetImagePaneCount( ptrSeedImage );

	for( int nPane=0;nPane<nPaneCount;nPane++ )
	{
		for(int y = 0; y < size.cy; y++ )
		{
			color *pSrc, *pDst;
			ptrSeedImage->GetRow( y, nPane ,&pSrc);
			ptrDestImage->GetRow( y, nPane ,&pDst );
			memcpy( pDst, pSrc, size.cx*sizeof(color) );
		}
	}

	return ReconstructionForClose(ptrSrcImage,ptrDestImage);
}


