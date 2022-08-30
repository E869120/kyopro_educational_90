def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y,x%y)

# 入力を受け取る
a, b, c = map(int, input().split())

# math.gcd()で最大公約数を求める
g = gcd(gcd(a, b), c)

#答えを出力する
print((a+b+c)//g-3)