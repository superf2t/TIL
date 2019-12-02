## compact
if 1:
    def compact(iterablethings):
        a = []
        idx = 0
        for x in iterablethings:
            if idx == 0 or x != a[idx -1]:
                a.append(x)
                idx += 1
        return iter(a)
