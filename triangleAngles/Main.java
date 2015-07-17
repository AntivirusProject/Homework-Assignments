package triangleAngles;

public class Main {

	public static void main(String[] args) {
		Triangle tri = new Triangle();
		
			tri.given(54, 12);
			
			System.out.println("The other angle is " + Triangle.otherAngle());
			System.out.println("The opposide side is " + tri.oppositeSide());
			System.out.println("The hypotenuse is " + tri.hypotenuse());
	}



}
