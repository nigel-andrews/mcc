%top{
}

id      [_a-zA-Z][a-zA-Z0-9_]*
eol     \r?\n
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
{eol}   out() << "$\n";
%%
