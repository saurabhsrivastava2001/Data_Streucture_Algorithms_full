// You are using Java
import java.util.Scanner;

class A{
    void afunc(){
        System.out.println(" we are inside the method of a class");
    }
    
}

class B extends A{
    void bfunc(){
        System.out.println("we are inside the method of b class");
    }
}

class call{
    public static void main(String args[]){
        boolean istrue=true;
    Scanner sc = new Scanner(System.in);
    B obj= new B();
    int choice=sc.nextInt();
    System.out.println("enter your choice: ");
    while(istrue){
        switch (choice){
            case 1:
                System.out.println("we are performing inheritance: ");
                System.out.println("we are calling the method of A class by the object of B: ");
                
                obj.afunc();
                istrue=false;
                break;
            default:
                System.out.println("inval input");
                
                
        }
    }
    }
    
}

