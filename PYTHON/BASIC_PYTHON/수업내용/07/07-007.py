#07-007.py

import pickle

D = {'A' : 65, 'B' : 66 }
with open('data.pkl', 'wb') as F:
    pickle.dump(D, F)
    pickle.dump([1, 2, 3, 4, 5], F)

with open('data.pkl', 'rb') as F:
    X = pickle.load(F)
    Y = pickle.load(F)

print(X, Y)    
