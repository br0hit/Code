`timescale 1ns/1ps

module testbench;

  reg [7:0] in1, in2;
  reg clk;
  reg [2:0] func;
  wire [7:0] result;

  Top DUT(in1, in2, func, clk, result);
 
  initial clk=0;
  always #5 clk = ~clk;
 
 
    initial 
      begin
      $monitor("in1:%d in2:%d func:%d result:%d clk:%d", in1, in2, func,result, clk);
      
        in1 = 12;
        in2 = 12;
        func = 0;
        clk = clk;
      #30
      
         in1 = 12;
        in2 = 8;
        func = 1;
      clk = clk;
      #30
          
        in1 = 8;
        in2 = 12;
        func = 2;
      clk = clk;
      #30
        
        in1 = 8;
        in2 = 12;
        func = 3;
        clk = clk;
      #30
        
        in1 = 8;
        in2 = 12;
        func = 4;
      clk = clk;
      #30
      
         in1 = 8;
        in2 = 12;
        func = 5;
      clk = clk;
      #30
      
        in1 = 8;
        in2 = 12;
        func = 6;
      clk = clk;
      #30
      
        in1 = 8;
        in2 = 12;
        func = 7;
      clk = clk;
      #30


      // Wait for a simulation time to observe results
     
        #100;
        $finish;
    end

endmodule