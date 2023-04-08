/*
두 날짜(YYYYMMDD)의 일 수 차이를 구하는 프로그램을 작성해 보자.

4년에 한번씩 1년이 366일이 되는데 이걸 윤년(Leap year)이라 한다.
하지만 100으로 나누어 떨어지되 400으로 나누어 떨어지지 않는 해는 평년(Common year)으로 한다.
*/
import java.util.HashMap;
public class SubDate {
    private static int isLeapYear(int year) {
        if(year % 4 == 0) {
            if(year % 100 == 0 && year % 400 != 0) {
                return 365;
            }
            else {
                return 366;
            }
        }
        else {
            return 365;
        }
    }

    private static int getYearDay(String year) {
        int result = 0;
        for(int i = 1 ; i < Integer.parseInt(year) ; i++) {
            result += isLeapYear(i);
        }
        return result;
    }

    public static int getTotalDay(String Date) throws RuntimeException {
        HashMap<Integer, Integer> dayOfMonth = new HashMap<>();
        dayOfMonth.put(1, 31);
        dayOfMonth.put(2, 28);
        dayOfMonth.put(3, 31);
        dayOfMonth.put(4, 30);
        dayOfMonth.put(5, 31);
        dayOfMonth.put(6, 30);
        dayOfMonth.put(7, 31);
        dayOfMonth.put(8, 31);
        dayOfMonth.put(9, 30);
        dayOfMonth.put(10, 31);
        dayOfMonth.put(11, 30);
        dayOfMonth.put(12, 31);

        String year = Date.substring(0, 4);
        String month = Date.substring(4, 6);
        String day = Date.substring(6, 8);
        if(year.equals("0000") || (Integer.parseInt(month) > 12 || Integer.parseInt(month) == 0) ||
                day.equals("00") || dayOfMonth.get(Integer.parseInt(month)) < Integer.parseInt(day)) {
            throw new RuntimeException("잘못된 입력이 있습니다.");
        }
        int result = 0;

        result += getYearDay(year);

        for(int i = 1 ; i < Integer.parseInt(month) ; i++) {
            result += dayOfMonth.get(i);
            if(i == 2 && isLeapYear(Integer.parseInt(year)) == 366) {
                result += 1;
            }
        }

        result += Integer.parseInt(day);

        return result;
    }

    public static int sub(String date1, String date2) {
        return Math.abs(getTotalDay(date1) - getTotalDay(date2));
    }

    public static void main(String[] args) {
        try {
            String date1 = "20070301";
            String date2 = "20070517";
            System.out.println(sub(date1 ,date2));
        }catch(RuntimeException re) {
            re.printStackTrace();
        }
    }
}