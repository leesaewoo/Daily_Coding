import java.io.File;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
public class Exercise_06 {
    public static void main(String[] args) throws IOException {
        FileWriter fw = new FileWriter("C:\\Users\\saewo\\Desktop\\sample.txt");
        fw.write("Life is too short\r\n");
        fw.write("you need python\r\n");

        fw.close();

        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\saewo\\Desktop\\sample.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\saewo\\Desktop\\tmp.txt"));

        String result = "";
        while((result = br.readLine()) != null) {
            result = result.replaceAll("python", "java");
            System.out.println(result);
            bw.write(result + "\r\n");
            bw.flush();
        }
        br.close();
        bw.close();

        File sample = new File("C:\\Users\\saewo\\Desktop\\sample.txt");
        File tmp = new File("C:\\Users\\saewo\\Desktop\\tmp.txt");
        sample.delete();
        tmp.renameTo(sample);

    }
}