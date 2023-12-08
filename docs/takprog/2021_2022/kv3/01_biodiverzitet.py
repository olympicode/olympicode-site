n, k = map(int, input().split())
niz = list(map(int, input().split()))
print(len(set(map(lambda x: x//k, niz))))
