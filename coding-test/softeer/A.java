import java.io.*;
import java.util.*;

public class A {
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;
		public static List<String> queue;

		static class Coord{
			public int x;
			public int y;

			public Coord(int x, int y) {
				this.x = x;
				this.y = y;
			}

			@Override
			public boolean equals(Object crd) {

				if(crd == this) {
					return true;	
				}

				if(!(crd instanceof Coord)) {
					return false;	
				}

				Coord crds = (Coord) crd;

				if(crds.x == this.x) {
					if(crds.y == this.y) {
						return true;
					}	
				}
				return false;
			}
			
		}

    public static void solve() throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine(), ",");
			Set<Coord> round1 = new HashSet<>();
			Set<Coord> round2 = new HashSet<>();
			Set<Coord> round3 = new HashSet<>();
			Set<Coord> round4 = new HashSet<>();
			Set<Coord> round5 = new HashSet<>();
			Set<Coord> round6 = new HashSet<>();
			Set<Coord> round7 = new HashSet<>();
			Set<Coord> round8 = new HashSet<>();
			Set<Coord> round9 = new HashSet<>();

			round1.add(new Coord(11,2));
			round1.add(new Coord(11,3));
			round1.add(new Coord(11,4));
			round1.add(new Coord(12,2));
			round1.add(new Coord(12,3));
			round1.add(new Coord(12,4));
			round1.add(new Coord(13,3));
			round1.add(new Coord(13,4));

			round2.add(new Coord(2, 11));
			round2.add(new Coord(2, 12));
			round2.add(new Coord(3, 11));
			round2.add(new Coord(3, 12));
			round2.add(new Coord(3, 13));
			round2.add(new Coord(4, 11));
			round2.add(new Coord(4, 12));
			round2.add(new Coord(4, 13));

			round3.add(new Coord(2, 3));
			round3.add(new Coord(2, 4));
			round3.add(new Coord(3, 2));
			round3.add(new Coord(3, 3));
			round3.add(new Coord(3, 4));
			round3.add(new Coord(4, 2));
			round3.add(new Coord(4, 3));
			round3.add(new Coord(4, 4));

			round4.add(new Coord(11, 11));
			round4.add(new Coord(11, 12));
			round4.add(new Coord(11, 13));
			round4.add(new Coord(12, 11));
			round4.add(new Coord(12, 12));
			round4.add(new Coord(12, 13));
			round4.add(new Coord(13, 11));
			round4.add(new Coord(14, 12));

			round5.add(new Coord(6, 0));
			round5.add(new Coord(6, 1));
			round5.add(new Coord(6, 14));
			round5.add(new Coord(6, 15));
			round5.add(new Coord(7, 0));
			round5.add(new Coord(7, 1));
			round5.add(new Coord(7, 14));
			round5.add(new Coord(7, 15));
			round5.add(new Coord(8, 0));
			round5.add(new Coord(8, 1));
			round5.add(new Coord(8, 14));
			round5.add(new Coord(8, 15));
			round5.add(new Coord(9, 0));
			round5.add(new Coord(9, 1));
			round5.add(new Coord(9, 14));
			round5.add(new Coord(9, 15));

			for(int i = 2; i <= 13; i++) {
				if (i == 7 || i == 8) {
					continue;	
				}
				for(int j = 7; j <= 8; j++) {
					round6.add(new Coord(j, i));
				}	
			}

			for(int i = 2; i <= 13; i++) {
				if (i == 7 || i == 8) {
					continue;	
				}
				for(int j = 7; j <= 8; j++) {
					round7.add(new Coord(i, j));
				}	
			}


			for(int i = 6; i <= 9; i ++) {
				round8.add(new Coord(0, i));
				round8.add(new Coord(1, i));
				round8.add(new Coord(14, i));
				round8.add(new Coord(15, i));
			}

			for(int i = 7; i <= 8; i++) {
				for(int j = 7; j <= 8; j++)	{
					round9.add(new Coord(i, j));
				}
			}

			Map<Integer, Set<Coord>> coords = new HashMap<>();

			coords.put(1, round1);
			coords.put(2, round2);
			coords.put(3, round3);
			coords.put(4, round4);
			coords.put(5, round5);
			coords.put(6, round6);
			coords.put(7, round7);
			coords.put(8, round8);
			coords.put(9, round9);

			List<Integer> result = new ArrayList<>();

			while(st.hasMoreTokens()) {
				result.add(Integer.parseInt(br.readLine()));
			}

			int len = result.size();
			int round = len / 6;
			int lastScore = 40;

			for(int i = 0; i < round; i++) {

				int count = 0;
				Coord coord1 = new Coord(result.get(i * 6), result.get(i * 6 + 1));
				Coord coord2 = new Coord(result.get(i * 6 + 2), result.get(i * 6 + 3));
				Coord coord3 = new Coord(result.get(i * 6 + 4), result.get(i * 6 + 5));

				Set<Coord> rounds = coords.get(i + 1);

				if(rounds.contains(coord1)) {
					count++;	
				}

				if(rounds.contains(coord2)) {
					count++;	
				}

				if(rounds.contains(coord3)) {
					count++;	
				}

				if(count == 0) {
					lastScore =(int) Math.round((double)lastScore / (double)2);
					continue;
				}

				lastScore += (i + 1) * count;
					
			}

			sb.append(lastScore).append("\n");
					
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

