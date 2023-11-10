// Code your testbench here
// or browse EAamples

/*
    Header:

    Assignment:Verilog Assignment 4
    Problem number:1
    Group no. 29

    Bannuru Rohit Kumar Reddy - 21CS30011
    Dumpala Hashmitha - 21CS10023
*/


module booth_tb;

  reg clk, rst, start;
  reg signed [7:0] A, M;
  wire signed [15:0] Z; 
  wire valid;

  always #5 clk = ~clk;

  Booth_Multiplication inst (clk, rst, start, A, M, valid, Z);

  initial begin
    clk = 1'b1;
    rst = 1'b0;
    start = 1'b0;

    A = 5;
    M = 3;
    #10 rst = 1'b1;
    #10 start = 1'b1;
    #10 start = 1'b0;

    
    // Print the product of the 2 numbers:

    @(posedge valid);
    
    $display("Test case when both the numbers are positive:");
    
    if (A[7]) begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end else begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end

    A = 5;
    M = -3;
    #10 start = 1'b1;
    #10 start = 1'b0;

    @(posedge valid);

    $display("Test case when A is positive and M is negative :");

    if (A[7]) begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end else begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end

    A = -5;
    M = -3;
    #10 start = 1'b1;
    #10 start = 1'b0;

    @(posedge valid);

    $display("Test case when both are negative :");


    if (A[7]) begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end else begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end

    A = 0;
    M = 3;
    #10 start = 1'b1;
    #10 start = 1'b0;

    @(posedge valid);

    $display("Test case when one of them is 0 :");


    if (A[7]) begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end else begin
      $display("Product of %d and %d:%d\n", A, M, Z);
    end

    $finish;
  end
endmodule
