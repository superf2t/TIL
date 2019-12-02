#087-015.py

import os, glob
dircnt = filecnt = 0
def tree(path, depth):
    global dircnt, filecnt    
    for x in glob.glob(path + '\\*'):
        prefix =  '|--' if depth == 0 else '|' + '--' * depth + '|--'
        if os.path.isdir(x):
            dircnt += 1
            print(prefix + os.path.basename(x))
            tree(x, depth + 1)
        elif os.path.isfile(x):
            filecnt += 1
            print(prefix + os.path.basename(x))
        else:
            print(prefix + 'unknown : ', x)

os.chdir('C:\\Program Files\\')
tree('.', 0)       
print('total ', dircnt, 'directories', filecnt, 'files')

