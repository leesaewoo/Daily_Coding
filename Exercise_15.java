import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
public class Exercise_15 {
    public static void main(String[] args) {
        try {
            FileWriter fw = new FileWriter("C:\\Users\\saewo\\Desktop\\sample.txt");
            fw.write("70\r\n60\r\n55\r\n75\r\n95\r\n90\r\n80\r\n80\r\n87\r\n100");
            fw.close();

            BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\saewo\\Desktop\\sample.txt"));
            String readLine;
            ArrayList<String> arrayList = new ArrayList<>();
            while((readLine = br.readLine()) != null) {
                arrayList.add(readLine);
            }
            br.close();

            double sum = 0;
            for(int i = 0 ; i < arrayList.size() ; i++) {
                sum += Integer.parseInt(arrayList.get(i));
            }
            BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\saewo\\Desktop\\result.txt"));
            double average = sum / arrayList.size();
            bw.write(String.valueOf(average));
            bw.close();
        }catch(IOException ioe) {
            System.out.println("ioe");
        }catch(IllegalArgumentException iae) {
            System.out.println("iae");
        }
    }
}
