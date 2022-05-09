//
//  ViewController.swift
//  TemperatureConverter
//
//  Created by Alexander Korchak on 08.05.2022.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var displayResult: UILabel!
    
    @IBOutlet weak var celcius: UITextField!
    
    @IBOutlet weak var fahrenheit: UITextField!
    
    var celciusValue: Double = 0.0
    var fahrenheitValue: Double = 0.0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func celciusToFahrenheit(_ sender: UIButton) {
       
        let degreesValue: Double? = Double(celcius.text!)
        if degreesValue != nil {
        fahrenheitValue = (degreesValue! * 9/5) + 32
        }
        displayResult.text = String(fahrenheitValue) + " Degrees"
        view.backgroundColor = .green
        
    }
    
    @IBAction func fahrenheitToCelcius(_ sender: UIButton) {
        let fahrenheitValue: Double? = Double(fahrenheit.text!)
        if fahrenheitValue != nil {
        celciusValue = (fahrenheitValue! - 32) * 5/9
        }
        displayResult.text = String(celciusValue) + " Degrees"
        view.backgroundColor = .yellow
    }

    
}

