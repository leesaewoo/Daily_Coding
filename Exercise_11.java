import java.io.IOException;
import java.util.Scanner;
import java.util.InputMismatchException;
class Pagination {
    private int toTalPage;
    public int getTotalPage(int totalPost, int postPerPage) {
        if(totalPost % postPerPage != 0)
        this.toTalPage = totalPost / postPerPage + 1;
        else {
            this.toTalPage = totalPost / postPerPage;
        }
        return this.toTalPage;
    }
}
public class Exercise_11 {
    public static void main(String[] args) throws IOException {
        System.out.println("페이징 하였을 때 총 페이지 수를 출력하는 프로그램입니다.\n종료하려면 end 입력해주세요.");
        Pagination pagination = new Pagination();
        Scanner scanner = new Scanner(System.in);
        int totalPost;
        int postPerPage;
        while(true) {
            System.out.println("게시물의 총 건수와 한 페이지에 보여줄 게시물 수를 공백(띄어쓰기)으로 구분지어 입력해 주세요.\nex)100 5");
            try {
                totalPost = scanner.nextInt();
                postPerPage = scanner.nextInt();
                System.out.println(totalPost + " " + postPerPage);
            } catch (InputMismatchException e) {
                String isEnd = scanner.nextLine();
                if(isEnd.toLowerCase().equals("end")) {
                    System.out.println("프로그램이 종료되었습니다.");
                    break;
                }
                System.out.println("잘못된 입력입니다.\n");
                continue;
            }
            System.out.println("결과값 : " + pagination.getTotalPage(totalPost, postPerPage) + "\n종료하려면 end 입력해주세요.");
        }
    }
}
