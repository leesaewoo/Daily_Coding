package com.codestates.seb.calculator;
import java.util.Scanner;
import java.text.DecimalFormat;
public class Calculator {
  public static void main(String[] args) {
        /*
            요구 사항에 따라 간단한 계산기를 만들어주세요.
            1. 사용자의 입력으로 첫 번째 숫자, 연산자, 두 번째 숫자를 받아야 합니다.
            2. 연산자의 종류는 +, -, *, / 입니다.
            3. 소수점 연산을 수행할 수 있어야 합니다.
            4. 연산 결과를 콘솔에 출력합니다.
        */
    System.out.println("===Java Calculator===");

    Scanner scanner = new Scanner(System.in);
    DecimalFormat decimalFormat = new DecimalFormat();
    SimpleCalculator simpleCalculator = new SimpleCalculator();

    while(true) {
      System.out.println("계산식을 입력해 주세요. (종료: \"end\" 입력)");
      System.out.println("Ex) 3 + 4");

      try {
        String inputString = scanner.nextLine();

        if(inputString.equalsIgnoreCase("end")) {
          System.out.println("종료되었습니다.");
          break;
        }

        System.out.printf("계산된 값: %s\n\n", decimalFormat.format(simpleCalculator.calculate(inputString)));

      } catch (Exception e) {
        System.out.println("잘못된 입력입니다. 다시 입력해 주세요");
      }
    }
  }
}

class SimpleCalculator {
  private double firstNum;
  private char operator;
  private double secondNum;
  private String inputString;

  double calculate(String inputString) throws Exception {
    this.inputString = inputString;
    //입력값(inputString)에서 첫 번째 숫자(firstNum), 연산자(operator), 두 번째 숫자(secondNum)를 추출
    //입력값 첫 자리에 음수를 나타내는 '-'가 들어올 수도 있기 때문에 두 번째 자리부터 탐색
    for (int i = 1; i < this.inputString.length(); i++) {
      if (this.inputString.charAt(i) == '+' || this.inputString.charAt(i) == '-' || this.inputString.charAt(i) == '*'
              || this.inputString.charAt(i) == '/') {
        this.firstNum = Double.parseDouble(this.inputString.substring(0, i).trim());
        this.secondNum = Double.parseDouble(this.inputString.substring(i + 1, inputString.length()).trim());
        this.operator = inputString.charAt(i);
        break;
      }

      if (i == inputString.length() - 1) {
        throw new Exception();
      }
    }

    switch (this.operator) {
      case '+':
        return this.firstNum + this.secondNum;

      case '-':
        return this.firstNum - this.secondNum;

      case '*':
        return this.firstNum * this.secondNum;

      case '/':
        return this.firstNum / this.secondNum;

      default:
        throw new Exception();
    }
  }
}