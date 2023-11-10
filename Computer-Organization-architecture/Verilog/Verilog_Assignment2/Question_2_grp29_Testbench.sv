Testbench.v
 
 
// Verilog Assignment-2
// Problem 2 ->testbench.v
// Group-29
// Dumpala Hashmitha(21CS10023)
// Bannuru Rohit Kumar Reddy(21CS30011)
 
// Specify the time scale for simulation
`timescale 1ns/1ps 
 
// Define the testbench module
module tb_Calculate_GCD;
 
  // Define testbench inputs
  reg [7:0] A, B;
  reg clk;
  
  // Define testbench outputs
  wire [7:0] C;
  wire [7:0] a_change, b_change;
  
  // Instantiate the Design Under Test (DUT) module
  Calculate_GCD DUT(A, B, C, a_change, b_change, clk);
  
  // Initialize the clock signal
  initial clk=0;
  
  // Generate a clock signal with a period of 5 time units
  always #5 clk = ~clk;
    
     initial 
     begin
      // Monitor and display values of a_change, b_change, GCD (C), and clk
      $monitor("A :%d B : %d GCD=%d, clk=%d", a_change, b_change, C, clk);
      // Set initial values for A and B
      A = 4;
      B = 12;
      clk = clk;  // initialise clock value 
      #100                    // Wait for 100 time units
      
      // Update values for A and B
      A = 14;
      B = 35;
      clk = clk;  //  initialise clock values
      #100                    // Wait for 100 time units
      
      // Wait for a simulation time to observe results
      #100; 
      $finish;
    end
 
endmodule