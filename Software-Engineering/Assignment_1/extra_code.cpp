// Polyn* Create_new_Polynomial()
// {
// 	int i,degree;

// 	cout<<"Enter the Degree of the polynomial to be created :"<<endl;
// 	cin>>degree;

// 	Polyn *P;
// 	P = (Polyn *)malloc(sizeof(Polyn));

// 	Polyn *temp;
// 	temp=P;


// 	cout<<"Enter the co-efficients of the polynomial in the increasing order of degree"<<endl<<"Please type 0 if coefficient of a particular degree doesnt exist"<<endl;

// 	for(i=0;i<degree+1;i++)
// 	{
// 		cin>>temp->coeff;
// 		temp=temp->next;

// 		temp = (Polyn *)malloc(sizeof(Polyn));
// 	}

// 	temp->next=NULL;

// 	return P;
// }