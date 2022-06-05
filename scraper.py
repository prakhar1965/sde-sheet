from bs4 import BeautifulSoup as bs
import requests
import os


page = requests.get("https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/")

soup = bs(page.content)

def get_description(code_studio_link):
    try:
        code_studio_page = requests.get(code_studio_link)
        content = bs(code_studio_page.content)
        description = content.find("codingninjas-problem-description")
        return description.text[0:17] + ':\n' + description.text[17:]
    except:
        return ""

def get_valid_fileName(file_name):
   return "".join(i for i in file_name if i not in "\/:*?<>|")

list_of_topics = soup.find_all("details")
cnt_topic = 0
for topic in list_of_topics[0:-4]:
    cnt_topic += 1
    topic_name = str(cnt_topic) + '.' + topic.find("summary").text.split(':')[1]
    os.makedirs(topic_name, exist_ok= True)
    questions = topic.find_all("tr")
    cnt_question = 0
    for question in questions[1:]:
        links = question.find_all("td")
        cnt_question += 1
        question_path = topic_name+ '/' + str(cnt_question) + '.' + get_valid_fileName(links[0].text)
        os.makedirs(question_path, exist_ok= True)
        
        question_file = open(question_path+"/solution.cpp", "w+")
        question_file_txt = open(question_path+"/problem_statement.txt", "wb")
            
        solution_link = links[0].find("a", href= True)
        if solution_link is not None:
            question_file.write("// Solution link: " + solution_link["href"] + "\n")
        
        code_studio_link = links[1].find("a", href= True)
        if code_studio_link is not None:
            link = code_studio_link.get('href')
            question_file.write("// CodeStudio link: " + link + "\n")
            problem_description = get_description(link)
        
        leetcode_link = links[3].find("a", href= True)
        if leetcode_link is not None:
            question_file.write("// Leetcode link: " + leetcode_link["href"])

        question_file_txt.write(problem_description.encode("utf-8"))       
        question_file.close()
        question_file_txt.close()
    print("Done extracting for topic " + topic_name)
        

    

