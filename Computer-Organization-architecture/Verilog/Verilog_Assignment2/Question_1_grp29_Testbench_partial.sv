`timescale 1ns/1ps

module testbench;

    // Inputs
    reg [15:0] inputNumber;
    reg [2:0] registerNumber;
    reg load;
    reg enable;

    // Outputs
    wire [15:0] outputData;

    // Instantiate the RegisterBank module
    RegisterBank dut (
        .inputNumber(inputNumber),
        .registerNumber(registerNumber),
        .load(load),
        .enable(enable),
        .outputData(outputData)
    );

    // Clock generation
    reg clk = 0;
    always #5 clk = ~clk;
 
  initial begin
    $monitor("Input wire :%d Register Number:%d Load bit:%d Enable bit:%d Output Register:%d", inputNumber, registerNumber, load, enable, clk, outputData );
   
    #100
   
        inputNumber = 2434;
        registerNumber = 3'b010;
        load = 1;
        enable = 0;
   

    #100
   
        inputNumber = 1234;
        registerNumber = 3'b010;
        load = 0;
        enable = 1;

    #100
   
        inputNumber = 1234;
        registerNumber = 3'b010;
        load = 1;
        enable = 0;

    #100
   
        inputNumber = 1234;
        registerNumber = 3'b010;
        load = 1;
        enable = 1;

      #100
           
        #100;
        $finish;
    end

endmodule



