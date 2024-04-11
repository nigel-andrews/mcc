%top{
}

id      [_a-zA-Z][a-zA-Z0-9_]+
INT     [0-9]+

%%
return  out() << "return";
void    out() << "void";
int     out() << "int";
{INT}   out() << "integer : " << text();
"("     out() << "(";
")"     out() << ")";
"{"
{id}    out() << "id : " << text();
\n      out() << "newline";
%%
