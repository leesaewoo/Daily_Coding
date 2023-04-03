import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.io.File;
public class Exercise_14 {
    public static void main(String[] args) {
        try {
            FileWriter fw = new FileWriter("C:\\Users\\saewo\\Desktop\\abc.txt");
            fw.write("AAA\r\n");
            fw.write("BBB\r\n");
            fw.write("CCC\r\n");
            fw.write("DDD\r\n");
            fw.write("EEE\r\n");
            fw.close();
        }catch(IOException ioe) {

        }

        try {
            BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\saewo\\Desktop\\abc.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\saewo\\Desktop\\tmp.txt"));
            ArrayList<String> arrayList = new ArrayList<>();
            String isNull = "";
            while((isNull = br.readLine()) != null) {
                arrayList.add(isNull);
            }

            for(int i = arrayList.size() - 1 ; i >= 0 ; i--) {
                bw.write(arrayList.get(i) + "\r\n");
                bw.flush();
            }

            br.close();
            bw.close();
        }catch (IOException ioe) {

        }

        File abc = new File("C:\\Users\\saewo\\Desktop\\abc.txt");
        File tmp = new File("C:\\Users\\saewo\\Desktop\\tmp.txt");

        abc.delete();
        tmp.renameTo(abc);
    }
}
