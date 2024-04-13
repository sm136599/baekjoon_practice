words = []
while True:
    word = list(map(str, input().strip()))
    if '-' in word:
        break
    tmp = {ch: 0 for ch in word}
    for ch in word:
        tmp[ch] += 1
    words.append(tmp)

answers = []
while True:
    char = list(map(str, input().strip()))
    if '#' in char:
        break
    box = {ch: 0 for ch in char}
    for ch in char:
        box[ch] += 1
    
    cnts = {ch: 0 for ch in box}
    for word in words:
        flag = True
        for key, value in word.items():
            if key not in box:
                flag = False
                break
            else:
                if box[key] < value:
                    flag = False
                    break
        if flag:
            for key in word.keys():
                cnts[key] += 1
    
    minn = min(cnts.values())
    maxx = max(cnts.values())
    mins = [key for key, value in cnts.items() if value == minn]
    maxs = [key for key, value in cnts.items() if value == maxx]

    answer = ''
    for c in sorted(mins):
        answer += c
    answer += ' ' + str(minn) + ' '
    for c in sorted(maxs):
        answer += c
    answer += ' ' + str(maxx)
    answers.append(answer)

for answer in answers:
    print(answer)