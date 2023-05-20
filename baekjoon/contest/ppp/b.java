
import java.io.*;
import java.util.*;

public class b{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());

			List<Integer> diffs = new ArrayList<>();


			while(st.hasMoreTokens()) {
				diffs.add(Integer.parseInt(st.nextToken()));
			}
			Collections.sort(diffs);

			int MIN = -1;
			int minValue = -1;

			for(int i = 0; i < n - 1; i++){
				Integer first = diffs.get(i);
				Integer second  = diffs.get(i + 1);

				Integer mid = (first + second) / 2;

				if(first.equals(mid) || second.equals(mid)) {
					continue;	
				}

				int value = Math.min(mid - first, second - mid);

				if(value > minValue) {
					minValue = value;	
					MIN = mid;
				}
			}

			sb.append(MIN).append("\n");


    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        solve();
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

