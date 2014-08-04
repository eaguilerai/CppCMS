#line 1 "my_skin.tmpl"
#include "content.h" 
#line 2 "my_skin.tmpl"
namespace my_skin {
	#line 3 "my_skin.tmpl"
	struct message :public cppcms::base_view
	#line 3 "my_skin.tmpl"
	{
	#line 3 "my_skin.tmpl"
		content::message &content;
	#line 3 "my_skin.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "my_skin.tmpl"
		{
	#line 3 "my_skin.tmpl"
		}
		#line 4 "my_skin.tmpl"
		virtual void render() {
			#line 7 "my_skin.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <body>\n"
				"        <h1>";
			#line 7 "my_skin.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 10 "my_skin.tmpl"
			out()<<" World!</h1>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 10 "my_skin.tmpl"
		} // end of template render
	#line 11 "my_skin.tmpl"
	}; // end of class message
#line 12 "my_skin.tmpl"
} // end of namespace my_skin
#line 12 "my_skin.tmpl"
namespace {
#line 12 "my_skin.tmpl"
 cppcms::views::generator my_generator; 
#line 12 "my_skin.tmpl"
 struct loader { 
#line 12 "my_skin.tmpl"
  loader() { 
#line 12 "my_skin.tmpl"
   my_generator.name("my_skin");
#line 12 "my_skin.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 12 "my_skin.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 12 "my_skin.tmpl"
 }
#line 12 "my_skin.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 12 "my_skin.tmpl"
} a_loader;
#line 12 "my_skin.tmpl"
} // anon 
