universe = vanilla 
Executable =/cms/kyriacou/Stealth_18/CMSSW_7_0_0/src/TT/Cuts
Requirements = (Arch == "X86_64")
Output = ./logs/$(Process).out
Error  = ./logs/$(Process).err
Log    = ./logs/$(Process).log

arguments =$(Process)

 
Queue 770

