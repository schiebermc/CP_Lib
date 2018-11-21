

def match(d1, d2):
    for sub in d1:
        if(sub in d2):
            return True
    return False

def substring_dict(s, n):
    d = set([])
    for i in range(len(s)-n+1):
        sub = s[i:i+n]
        d.add(sub)
    return d

def do_these_words_match(s1, s2):

    pos = False
    for n in range(1, min(len(s1), len(s2))+1):
        d1 = substring_dict(s1, n)
        d2 = substring_dict(s2, n)

        if(match(d1, d2)):
            pos = True
            break

    return pos


