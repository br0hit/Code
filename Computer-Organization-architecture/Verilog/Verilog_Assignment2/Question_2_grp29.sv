// Verilog Assignment-2
// Problem 2 ->design.v
// Group-29
// Dumpala Hashmitha(21CS10023)
// Bannuru Rohit Kumar Reddy(21CS30011)
 
 
// Specify the time scale for simulation
`timescale 1ns/1ps
 
// Define the module Calculate_GCD
module Calculate_GCD (A,B,C,a_change,b_change,clk);
  
  // Define inputs
  input  [7:0] A,B;
  input clk;
  
  // Define outputs
  output [7:0] C;
  output [7:0] a_change, b_change;
 
  // Define internal registers
  reg [7:0] C;
  reg [7:0] a_change, b_change;
  reg [7:0] temp_A;
  reg [7:0] temp_B;
  
 // For Every Example of the test bench if A or B Change we have to run the code again 
  
  // This always block captures the values of A and B when they change
  always @ (A or B)
    begin
      temp_A = A;       // Store the current value of A
      temp_B = B;       // Store the current value of B
      a_change = A;     // Store the current value of A in a_change
      b_change = B;     // Store the current value of B in b_change
    end
 
  // This always block computes the GCD using Euclidean algorithm
  always @ (posedge clk)
    begin
      if(temp_A > temp_B)
        begin
          temp_A <= temp_A - temp_B; // Subtract B from A
          a_change <= temp_A;                // Update a_change
        end
       else if (temp_B > temp_A)
        begin
          temp_B <= temp_B - temp_A; // Subtract A from B
          b_change <= temp_B;                // Update b_change
        end
       else 
         C <= temp_A;                                           // A and B are equal, so GCD is A
         a_change <= temp_A;                 // Update a_change
         b_change <= temp_B;         // Update b_change
    end
 
endmodule