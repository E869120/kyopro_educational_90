N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
Answer = 0
 
for i in range(0, N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            for l in range(k + 1, N):
                for m in range(l + 1, N):
                    v = ((((A[i] * A[j] % P) * A[k] % P) * A[l] % P) * A[m]) % P
                    if v == Q:
                        Answer += 1
 
print(Answer)