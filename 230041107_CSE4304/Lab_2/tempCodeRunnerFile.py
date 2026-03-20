s = "g6856984678470918376798472216366826920847269638376798793"
s = chr(ord(s[0]) - 49) + s[1:]

out = ""
for i in range(0, len(s), 2):
    d = int(s[i:i+2])
    out += chr(d + 32)

print(out)
