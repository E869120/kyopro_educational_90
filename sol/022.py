import math

# 入力を受け取る
a, b, c = map(int, input().split())

# math.gcd()で最大公約数を求める
g = math.gcd(math.gcd(a, b), c)

#答えを出力する
print((a+b+c)//g-3)
