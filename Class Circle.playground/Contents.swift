import Cocoa

class Circle {
    var radius: Double = 0.0
    let PI: Double = 3.14159
    
    init(radius: Double) {
        self.radius = radius
    }

    func getRadius() -> Double {
        radius
    }
    
    func getArea() -> Double {
        let area: Double = PI * radius * radius;
        return area
    }
    
    func getDiameter() -> Double {
        let diameter = radius * 2
        return diameter
    }
    
    func getCircumference() -> Double {
        let circumference: Double = 2 * PI * radius
        return circumference
    }
}

let circle = Circle(radius: 10)

print("Circle's area: \(circle.getArea())\n")
print("Circle's diameter: \(circle.getDiameter())\n")
print("Circle's circumference: \(circle.getCircumference())\n")

