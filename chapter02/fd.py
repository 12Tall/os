import sys

if len( sys.argv ) != 3:
   print 'Usage: ', sys.argv[0], 'BinFileName ImgFileName'
sys.exit()
fin = file( sys.argv[1], 'rb' )
bufbin = fin.read( 512 )
fin.close() 
bufbin += ( '/0' * ( 1474560 - 512 ) )
fout = file( sys.argv[2], 'wb' )
fout.write( bufbin )
fout.close()