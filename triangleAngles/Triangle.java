package triangleAngles;

import java.math.*;

class Triangle {
	static double angle;
	static double oAngle;
	static double opp;
	static double hyp;
	double adj;
	
	void given(double a, double ad){
		angle = a;
		adj = ad;
		
	}
	
	static double otherAngle(){
		oAngle = 180 - 90 - angle;
		
		return oAngle;
	}
	
	double oppositeSide(){
		opp = Math.tan(angle) / adj;
		
		return opp;
	}
	
	double hypotenuse(){
		hyp = Math.cos(angle) / adj;
		
		return hyp;
	}
	

}
