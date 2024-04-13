%top{
}

id      [_a-zA-Z][a-zA-Z0-9_]*
eol     \r?\n
ws      [\t ]
INT     [0-9]+

%%
return  out() << "return";
void    out() << "void";
int     out() << "int";
{INT}   out() << "int_" << text();
"("     out() << "(";
")"     out() << ")";
"{"     out() << "{";
"}"     out() << "}";
{id}    out() << "id_" << text();
";"     out() << ";";
{eol}   out() << "$\n";
{ws}    out() << text();
.       out() << "Unknown symbol : " << text();
%%
