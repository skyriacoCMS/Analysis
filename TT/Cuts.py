import os 
import sys


i = sys.argv[1]
cmnd = 'root -b -q -l "CUTS.C('+i+',5,-1,-1,-1)"'
os.system('cp ../Templates/CUTS.C .')
os.system('cp ../Templates/xsecs.h .')
os.system(cmnd)


