universe = vanilla 
Executable =/cms/kyriacou/Stealth_18/CMSSW_7_0_0/src/QCD/Q52/Ens
Requirements = (Arch == "X86_64")
Output = ./Q52/logs/$(Process).out
Error  = ./Q52/logs/$(Process).err
Log    = ./Q52/logs/$(Process).log

arguments =$(Process)

 
Queue 40

