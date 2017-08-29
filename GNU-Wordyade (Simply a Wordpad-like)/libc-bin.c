

char *binstrrlf(char *str)
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



char *binstrcut( char *str , int myposstart, int myposend )
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
      // in c++, need to cast the return of (char*)malloc();
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;
}









void runwith( char *thecmd , char *thefile ){
       char cmdi[PATH_MAX];
       printf( "<CMD: %s>\n" , thecmd ) ; 
       printf( "<FILE: %s>\n" , thefile ) ; 
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , thefile , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
}


void nrunwith( char *thecmd , char *thefile ){
       char cmdi[PATH_MAX];
       printf( "<CMD: %s>\n" , thecmd ) ; 
       printf( "<FILE: %s>\n" , thefile ) ; 
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , thefile , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
}



void nruncmd( char *thecmd ){
       char cmdi[PATH_MAX];
       printf( "<CMD: %s>\n" , thecmd ) ; 
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
}




// static int compare_fun( const void *p, const void *q){
//   const char *l = p ; 
//   const char *r = q ; 
//   int cmp; 
//   cmp = strcmp( l, r );
//   return cmp; 
// }


int fexist(char *a_option){
  char dir1[PATH_MAX]; 
  char *dir2;
  DIR *dip;
  strncpy( dir1 , "",  PATH_MAX  );
  strncpy( dir1 , a_option,  PATH_MAX  );

  struct stat st_buf; 
  int status; 
  int fileordir = 0 ; 

  status = stat ( dir1 , &st_buf);
  if (status != 0) {
    fileordir = 0;
  }

  // this is compatible to check if a file exists
  FILE *fp2check = fopen( dir1  ,"r");
  if( fp2check ) {
  // exists
  fileordir = 1; 
  fclose(fp2check);
  } 

  if (S_ISDIR (st_buf.st_mode)) {
    fileordir = 2; 
  }
return fileordir;
/////////////////////////////
}






char *filefetch( char *filesource , int linenbr){
  FILE *fp;
  FILE *fp1; 
  FILE *fp2;
  int counter = 0 ; 
  int freader = 1 ; 
  int i , j ,posy, posx ; 
  char linetmp[PATH_MAX] ;
  char line[PATH_MAX];
  char foundline[PATH_MAX] ;
  strncpy( foundline , "" , PATH_MAX );

  if ( fexist( filesource ) == 1 ){
        fp1 = fopen( filesource, "rb");
        counter = 0; 
	freader = 1;
        while( !feof(fp1) && ( freader == 1)   ) {
          strncpy( linetmp, "", PATH_MAX );
          fgets(linetmp, PATH_MAX, fp1); 
              strncpy(line, binstrrlf( linetmp ), PATH_MAX );
              if ( !feof(fp1) )
              {
                  counter++;
                  if ( counter == linenbr ) 
                     strncpy( foundline , line , PATH_MAX );
	      }
         }
        fclose(fp1);
    }

   size_t siz = sizeof foundline ; 
   char *r = (char*)malloc( sizeof foundline );
   return r ? (char*)memcpy(r, foundline, siz ) : NULL;
}




int filelinecount( char *filesource )
{
  FILE *fp;
  FILE *fp1; 
  FILE *fp2;
  int counter = 0 ; 
  int freader = 1 ; 
  int i , j ,posy, posx ; 
  char linetmp[PATH_MAX] ;
  char line[PATH_MAX];
  char foundline[PATH_MAX] ;
  strncpy( foundline , "" , PATH_MAX );
  if ( fexist( filesource ) == 1 ){
        fp1 = fopen( filesource, "rb");
        counter = 0; 
	freader = 1;
        while( !feof(fp1) && ( freader == 1)   ) {
          strncpy( linetmp, "", PATH_MAX );
          fgets(linetmp, PATH_MAX, fp1); 
              strncpy(line, binstrrlf( linetmp ), PATH_MAX );
              if ( !feof(fp1) )
              {
                  counter++;
	      }
         }
        fclose(fp1);
    }
   return counter-1;
}







int fdelete(char *thefile){
    int fooout = 0;
    if ( fexist( thefile ) == 1 ) {
      printf( "Delete %s (%d)\n", thefile , fexist( thefile  )  );
      unlink( thefile );
      fooout = 1;
    }
    return fooout ;
}


int frename(char *thesrc, char *thetrgt){
    int fooout = 0;
    if ( fexist( thesrc ) == 1 ) 
    {
      printf( "Rename %s (%d) => %s \n", thesrc , fexist( thesrc  ), thetrgt );
      if ( fexist( thetrgt ) == 1 ) unlink( thetrgt );
      rename( thesrc, thetrgt );
      fooout = 1;
    }
    return fooout ;
}



int chdirhome()
{
      chdir( getenv( "HOME" ) );
}



char *fbasename(char *name)
{
  //char *name;
  char *base = name;
  while (*name)
    {
      if (*name++ == '/')
	{
	  base = name;
	}
    }
  return (base);
}





char *fextension(char *str)
{     //seems to work
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=strlen(str)-1 ; str[i] !='.' ; i--)
      {
        if ( str[i] != '.' ) 
            ptr[j++]=str[i];
      } 
      ptr[j]='\0';

      char ptrout[strlen(ptr)+1];  
      j = 0; 
      for( i=strlen(ptr)-1 ;  i >= 0 ; i--)
            ptrout[j++]=ptr[i];
      ptrout[j]='\0';

      size_t siz = sizeof ptrout ; 
      char *r = (char*)malloc( sizeof ptrout );
      return r ? (char*)memcpy(r, ptrout, siz ) : NULL;
}






