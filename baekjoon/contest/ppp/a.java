
import java.io.*;
import java.util.*;

public class a{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());

			List<Integer> studyPlans = new ArrayList();

			while(st.hasMoreTokens()) {
				studyPlans.add(Integer.parseInt(st.nextToken()));
			}

			int result = 8 * (n - 1);

			for(int studyTime: studyPlans) {
				result += studyTime;
			}

			int days = result / 24;
			int hours = result % 24;

			sb.append(days).append(" ").append(hours);

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

