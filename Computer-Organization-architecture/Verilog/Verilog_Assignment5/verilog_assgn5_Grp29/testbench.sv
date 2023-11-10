// Code your testbench here
// or browse Examples


`timescale 1ns / 1ns
module tb_div255;

    // write a test bench to check the add function in alu module

  reg [31:0] x;
  wire [31:0]y;
  reg clk;
 
  top_level DUT(.x(x),.clk(clk),.y(y));

    initial clk = 0;
  initial x  = 32'd0;
 
    always #5 clk = ~clk;
 
 
   initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1);
  end

    initial begin
     
      $display("Assignment 5 Group 29");
     
      #100
      x= 510;
      #100;
      $display("x:%d  Division by 255:%d",x,y);

     
      x= 2550;
      #100;
      $display("x:%d  Division by 255:%d",x,y);

     
      x= 4335;
      #100;
      $display("x:%d  Division by 255:%d",x,y);
     
      x= 255;
      #100;
      $display("x:%d  Division by 255:%d ",x,y);
     
     
      $display("Note: The extra spaces are because we are considering a 32 bit number");
     
      $finish;

    end
 
endmodule