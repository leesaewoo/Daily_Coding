import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
class ReadLine {
    private String s;

    public void ToUppercase(BufferedReader br) throws IOException {
        while(true) {
            System.out.println("영문을 입력해 주세요 (중단하려면 \"END\" 또는 \"end\" 입력) ");
            s = br.readLine();
            char[] c = new char[s.length()];

            for(int i = 0 ; i < s.length() ; i++) {

                if((int)s.charAt(i) > 96 && (int)s.charAt(i) < 123) {
                    c[i] = (char)((int)s.charAt(i) - 32);
                }
                else {
                    c[i] = s.charAt(i);
                }
            }

            s = String.valueOf(c);

            if(s.equals("END")) {
                System.out.println("종료되었습니다.");
                break;
            }
            else {
                System.out.println("변환 : " + s);
            }
        }
    }
}
public class Exercise_05 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ReadLine rl = new ReadLine();
        rl.ToUppercase(br);
    }
}


/*
class ReadLine {
    private String s;

    public void ToUppercase(BufferedReader br) throws IOException {
        while(true) {
            System.out.println("영문을 입력해 주세요 (중단하려면 \"END\" 또는 \"end\" 입력) ");
            s = br.readLine();
            s = s.toUpperCase();

            if(s.equals("END")) {
                System.out.println("종료되었습니다.");
                break;
            }
            else {
                System.out.println("변환 : " + s);
            }
        }
    }
}
public class Exercise_05 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ReadLine rl = new ReadLine();
        rl.ToUppercase(br);
    }
}
 */