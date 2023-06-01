package pl.edu.zut.wi.po.newmath.tests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import pl.edu.zut.wi.po.newmath.Circle;

public class CircleTests {

	@Test
	public void testCircum() {
		assertEquals(12.56, Circle.circumference(2), 0.01);
	}

}
