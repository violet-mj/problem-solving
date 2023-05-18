# problem c
<a href="https://codeforces.com/contest/1832/problem/C">problem link</a>
$i$번째 contrast와 $i-1$번째 constrast가 있다고 가정해보자.
$|a_{i-1} - a_i| + |a_i - a_{i+1}|$ 만약 1번째 절댓값이 양수고 2번째 절댓값이 양수면
$a_{i-1} - a_i + a_i - a_{i+1}$로 나타낼 수 있다. $a_i$가 없어도 위 값은 같으므로 $a_i$는 빼도 무방하다.
반대로 1번째 절댓값이 음수고 2번째 절댓값이 음수인 경우에도 같다. 그러므로 $0$부터 $n-1$까지 확인하면서 뺄 수 있는 $a_i$를 찾으면된다
다만 모든 숫자가 같은경우 배열의 contrast가 0이므로 1을 반환하면 된다.
