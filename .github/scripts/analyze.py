import os
import subprocess
import google.generativeai as genai

# Gemini API 설정
genai.configure(api_key=os.environ["GEMINI_API_KEY"])
model = genai.GenerativeModel('gemini-1.5-flash')

def get_last_commit_cpp_files():
    """마지막 커밋에서 추가/수정된 .cc 또는 .cpp 파일을 찾습니다."""
    try:
        output = subprocess.check_output(['git', 'diff', '--name-only', 'HEAD~1', 'HEAD']).decode('utf-8')
        return [f for f in output.splitlines() if f.endswith(('.cc', '.cpp'))]
    except:
        return []

def analyze_and_save():
    files = get_last_commit_cpp_files()
    
    for file_path in files:
        if not os.path.exists(file_path): continue
        
        with open(file_path, 'r', encoding='utf-8') as f:
            code = f.read()

        prompt = f"""
        당신은 알고리즘 전문가입니다. 다음 C++ 코드를 분석하여:
        1. 핵심 로직의 흐름도를 Mermaid.js flowchart TD 형식으로 작성하세요.
        2. 시간 복잡도와 공간 복잡도를 짧게 설명하세요.
        
        오직 마크다운 형식으로만 응답하세요.
        코드:
        {code}
        """

        response = model.generate_content(prompt)
        
        # 분석 결과 저장 경로 (해당 문제 폴더 내 ANALYSIS.md)
        target_dir = os.path.dirname(file_path)
        analysis_path = os.path.join(target_dir, "ANALYSIS.md")
        
        with open(analysis_path, 'w', encoding='utf-8') as f:
            f.write(f"# 📊 Algorithm Analysis: {os.path.basename(file_path)}\n\n")
            f.write(response.text)
        print(f"Created analysis for {file_path}")

if __name__ == "__main__":
    analyze_and_save()