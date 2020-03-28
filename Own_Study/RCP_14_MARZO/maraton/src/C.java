import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class C {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int l,w,h,x,y,a;
		String ln1[] = br.readLine().split(" ");
		String ln2[] = br.readLine().split( " ");
		l = Integer.parseInt(ln1[0]);
		w = Integer.parseInt(ln1[1]);
		h = Integer.parseInt(ln1[2]);
		x = Integer.parseInt(ln2[0]);
		y = Integer.parseInt(ln2[1]);
		a = Integer.parseInt(ln2[2]);
		
		double vec[] = new double[2];
		vec[0] = Math.cos(Math.toRadians(a))*h+x-w;
		vec[1] = Math.sin(Math.toRadians(a))*h+y-l;
		//System.out.println(vec[0]+ " "+ vec[1]);
		if(vec[0]>0 || vec[1]>0) {
			if(Math.sqrt( Math.pow(vec[0], 2) + Math.pow(vec[1], 0)) / h >= 0.01) {
				bw.write("NO");
			}else {
				bw.write("YES");
			}
		}else {
			bw.write("YES");
		}
		
		
		bw.close();
	}

}
