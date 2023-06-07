import sys
from heapq import heappop, heappush
input = lambda: sys.stdin.readline().rstrip()
fprint = sys.stdout.write
INF = sys.maxsize

def solve():
    n, m, k = map(int, input().split())
    graph = [[] for i in range(n + 1)]

    for i in range(k):
        s, e, c, d = map(int, input().split())
        graph[s].append((e, c, d))

    distance = [[INF for i in range(m + 1)] for i in range(n + 1)]

    pq = []
    heappush(pq, (0, 0, 1))
    distance[1][0] = 0

    while pq:
        dist, cost, currNode = heappop(pq)

        if dist > distance[currNode][cost]:
            continue
        
        for nextNode, nextCost, nextDist in graph[currNode]:
            if cost + nextCost > m:
                continue
            if dist + nextDist >= distance[nextNode][cost + nextCost]:
                continue

            distance[nextNode][cost + nextCost] = dist + nextDist
            heappush(pq, (dist + nextDist, cost + nextCost, nextNode))

    min_ = INF
    for i in range(m + 1):
        min_ = min(min_, distance[n][i])

    return "Poor KCM" if min_ == INF else min_

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())

