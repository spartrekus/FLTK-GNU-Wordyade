
char *strtrim(char *str)
{ // seems to work 
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0;str[i]!='\0';i++)
      {
        if (str[i] != ' ' && str[i] != '\t') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;
}

char *strrlf(char *str)
{  // seems to work
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;
}

char *strsplit(char *str , int mychar , int myitem )
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      int fooitem = 0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( str[i] == mychar ) 
           fooitem++;
        //else if ( str[i] != mychar &&  fooitem == myitem-1  ) 
        else if ( str[i] != mychar &&  fooitem == myitem-2  ) 
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;
}




 
char *strcut( char *str , int myposstart, int myposend )
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;
}










