' VBScript part1Test CalcForGroups

eps = 0.0000001
Data.SetValue "\StatUI\CalcForGroups", ""
ClassifyObjectList "", "�������"

CreateStatTable "�������", "1TD"

CreateStatTable "�������", "All_TD"

CreateStatObject "1TD",  "ST1"

Data.SetValue "\StatUI\CalcForGroups", "0"
' reateStatObject "All_TD",  "All_ST"

Set objSt1 = Objects.GetObjectByName ("ST1")

