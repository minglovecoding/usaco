import os
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait, Select
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager

# ======= 配置区域 =======

USERNAME = "nlinn25"
PASSWORD = "5d81308"
BASE_DIR = "/Users/zhoumingzhao/Desktop/files/usaco/24-25-Feb"

FILES = {
    "https://usaco.org/index.php?page=viewproblem2&cpid=1491": "b1_1.cpp",
    "https://usaco.org/index.php?page=viewproblem2&cpid=1492": "b2_1.cpp",
    "https://usaco.org/index.php?page=viewproblem2&cpid=1493": "b3_1.cpp",
}
# =========================

# 启动浏览器
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))
driver.implicitly_wait(10)

def wait(by, value, timeout=10):
    return WebDriverWait(driver, timeout).until(EC.presence_of_element_located((by, value)))

try:
    # 登录 USACO
    driver.get("https://usaco.org/index.php?page=login")
    wait(By.NAME, "uname").send_keys(USERNAME)
    driver.find_element(By.NAME, "password").send_keys(PASSWORD)
    driver.find_element(By.XPATH, '//input[@type="submit" and @value="Login"]').click()
    print("✅ 登录成功")
    
    time.sleep(1)
    # 提交每个文件
    for url, filename in FILES.items():
        try:
            # 打开题目页面（此页已含提交表单） 
            driver.get(url)
            print("🌐 打开题目页面")
            
            
            # 1. 选择语言（如 C++17）
            Select(wait(By.NAME, "language")).select_by_visible_text("C++17")
            print("✅ 已选择语言：C++17")

            # 2. 上传代码文件
            file_path = os.path.join(BASE_DIR, filename)
            wait(By.NAME, "sourcefile").send_keys(file_path)
            print(f"📁 已选择文件：{filename}")

            # 3. 点击“Submit a Solution”按钮
            WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.NAME, "solution-submit"))
            ).click()
            print("✅ 提交成功")

            os.remove(file_path)
            print(f"🗑️ 已删除反查重文件：{filename}")

            time.sleep(5)

        except Exception as e:
            print(f"❗ 提交 {filename} 出错：{e}")
            driver.save_screenshot(f"error_{filename}.png")
            print(f"📸 错误页面截图已保存：error_{filename}.png")

    print("\n🎉 所有文件提交完成")

except Exception as e:
    print(f"❗ 登录出错：{e}")
    driver.save_screenshot("login_error.png")
    print("📸 登录失败截图已保存：login_error.png")

finally:
    print("OK")
    input("🔚 按下回车键后关闭浏览器并退出...")
    driver.quit()
    #driver.quit()
