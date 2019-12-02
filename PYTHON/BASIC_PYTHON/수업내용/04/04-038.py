#04-038.py

a = [ x*y for x in range(2, 10) for y in range(1, 10) ]
b = { x*y for x in range(2, 10) for y in range(1, 10) }
print ('size of a = ', len(a))
print ('size of b = ', len(b))

name = ['ki', 'kim', 'lew', 'moon', 'song']
score = [90, 80, 95, 100, 85]
score_dict = {key : value for key, value in zip(name, score)}
print(score_dict)

score = [('ki', 90), ('kim', 80), ('lew', 95), ('moon', 100), ('song', 85)]
score_dict = {t[0] : t[1] for t in score}
print(score_dict)

