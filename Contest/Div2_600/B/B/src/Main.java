import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer str= new StringTokenizer(br.readLine());
		long days[]= new long[n];
		for(int i =0; i< n;i++) {
			days[i]= Long.parseLong(str.nextToken());
		}
		TreeMap<Long,Integer> check= new TreeMap<Long, Integer>();
		boolean can=true;
		long cantDays=0;
		long cantEvents=0;
		long sum=0;
		ArrayList<Long> res= new ArrayList<Long>();
		for(int i =0; i<n;i++) {
			
			if(days[i]<0) {
				if(check.containsKey(-days[i])) {
					if(check.get(-days[i]).intValue() == 1) {
						check.put(-days[i], 0);
						cantEvents++;
						sum+=days[i];
						
					}else {
						can=false;
						break;
					}
				}else {
					
					can=false;
					break;
				}
			}else {
				
				if(check.containsKey(days[i])) {
					can=false;
					break;
				}else {
					check.put(days[i], 1);
					cantEvents++;
					sum+=days[i];
				}
			}
			if(sum == 0) {
				cantDays++;
				check = new TreeMap<Long, Integer>();
				res.add(cantEvents);
				cantEvents=0;

			}
		}
		if(sum != 0) {
			can=false;
		}
		if(can) {
			bw.write(cantDays+"\n");
			int len = res.size();
			for(int i =0;i<len;i++) {
				if(i+1==len) {
					bw.write(res.get(i).intValue()+"\n");
				}else {
					bw.write(res.get(i).intValue()+" ");
				}
			}
		}else {
			bw.write("-1\n");
		}
		bw.close();

	}

}
