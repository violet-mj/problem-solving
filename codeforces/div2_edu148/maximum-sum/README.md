# problem B
<a href="https://codeforces.com/contest/1832/problem/B">problem link</a><br>
이 문제를 naive하게 생각하면 연산을 할 수 있는 모든 경우를 생각해보면 된다. <br>
첫번째 연산을 $i$번 두번째 연산을 $k - i$번을 한다고 가정한다면. 모든 연산의 경우의 수는 $k$번 입니다.
그러므로 시간복잡도 $O(k)$로 문제를 풀 수 있습니다.
이 문제에서 주의할 점은 지워진 원소를 제외한 나머지 원소를 더해줘야 합니다. 
그 과정에서 합을 전처리하지 않고 모든 경우에 대해 더해주면 $O(nk)$가 되므로 array $a$의 누적합을 구해 모든 경우마다 합을 $O(1)$로 구할 수 있도록합니다.
