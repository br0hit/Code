// Header file containing the library API of all the files :

// Classes:

class Attr 
{ 
    //Base class for attributes

// Add operators for different attribute type in derived classes
public: virtual bool operator== (const Attr & right) = 0;
};

class Record 
{ 
    //storing data for each record
    // vector <Attr *> attrptr;
    //methods
};

class Relation
{
     // storing a relation
    int natttr, nrecs; // number of attributes and records
    // vector <string> attrnames; // schema
    // vector <int> attrinds; // mapping schema to indices
    // list <Record *> recs; // list of records
    // methods
};


// Union: All records of both R1 and R2.
Relation * union(Relation * R1, Relation * R2);

// Difference: Records in R1 but not in R2
Relation * difference (Relation * R1, Relation * R2);

// Cartesian Product: All possible pairs of records from R1 and R2
Relation * catersianproduct(Relation * R1, Relation * R2);

// Projection: New relation with a subset of columns
Relation * projection(Relation * R1, list<string> projectattrs);

/* Selection: New relation with a subset of records matching a boolean
expression in the attribute values in disjunctive normal form */
Relation * union (Relation * R1, DNFformula * f);

struct DNFformula { list <list <tuple <string, char, Attr *> >> ops; } 
/* is a list of list of tuples with each tuple representing a comparison.
The top level list stores disjunctions of clauses, each of which represents a list
of conjunctions of comparisons. For simplicity assume that there are no
negations.*/

// Rename: rename an attribute in schema
Relation * difference (Relation * R1, string s1, string s2)