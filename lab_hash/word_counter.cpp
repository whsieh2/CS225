/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

template <template <class K, class V> class HT>
WordFreq<HT>::WordFreq( const string & infile ) : filename( infile ) { /* nothing */ }

template <template <class K, class V> class HT>
vector< pair<string, int> > WordFreq<HT>::getWords( int threshold ) const {
    TextFile infile( filename );
    HT<string,int> hashtable(1024);
    while (infile.good())
    {
    	string word =  infile.getNextWord();
    	hashtable[word]++;
    }
    
    typename HT<string, int>::iterator it;
    vector< pair<string, int> > ret;
   
    for (it = hashtable.begin(); it != hashtable.end(); it++)
    {
    	if (it-> second >= threshold)
    		ret.push_back(*it);
    		
    }
    
    /**
     * @todo Implement this function.
     * @see char_counter.cpp if you're having trouble.
     */
    return ret;
}
